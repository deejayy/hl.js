#include "../node.h"
#include "../node_file.h"
#include "../node_buffer.h"
#include "../node_internals.h"
#include "../node_stat_watcher.h"

#include "../env.h"
#include "../env-inl.h"
#include "../req-wrap.h"
#include "../req-wrap-inl.h"
#include "../string_bytes.h"
#include "../util.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
# include <io.h>
#endif

#include <vector>

#include "sdk_util.h"

namespace node {

using v8::Array;
using v8::Context;
using v8::EscapableHandleScope;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Handle;
using v8::HandleScope;
using v8::Integer;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

static void ServerPrintf(const FunctionCallbackInfo<Value>& args) {
  Environment* env = Environment::GetCurrent(args.GetIsolate());
  HandleScope scope(env->isolate());

	for (int i=0; i < args.Length(); i++) {
		String::Utf8Value str(args[i]->ToString());
		UTIL_LogPrintf(*str);
	}
}


void InitHlds(Handle<Object> target,
            Handle<Value> unused,
            Handle<Context> context,
            void* priv) {

  UTIL_LogPrintf("InitHlds\n");

  Environment* env = Environment::GetCurrent(context);

  env->SetMethod(target, "server_printf", ServerPrintf);

  StatWatcher::Initialize(env, target);
}

}  // end namespace node

NODE_MODULE_CONTEXT_AWARE_BUILTIN(hlds, node::InitHlds)
