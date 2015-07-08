
hl.js
=====

embedding io.js into half life dedicated server (hlds)

```javascript
setInterval(function () {
    hlds.server_printf("helo from node\n");
}, 1000);
```

```text
L 07/08/2015 - 17:17:34: helo from node
L 07/08/2015 - 17:17:35: helo from node
stats
CPU   In    Out   Uptime  Users   FPS    Players
 7.00  0.00  0.00       0     0  652.79       0
L 07/08/2015 - 17:17:36: helo from node
L 07/08/2015 - 17:17:37: helo from node
```
