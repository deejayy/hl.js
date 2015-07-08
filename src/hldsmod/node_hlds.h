#ifndef SRC_NODE_HLDS_H_
#define SRC_NODE_HLDS_H_

#include "node.h"
#include "v8.h"

namespace node {

void InitHlds(v8::Handle<v8::Object> target);

}  // namespace node

#endif  // SRC_NODE_HLDS_H_
