# ctp-napi
基于N-api写的 node 扩展, 用于期货ctp的交易和行情.

`$ git clone git@github.com:charmer1989/ctp-napi.git && cd ctp-napi`

`$ npm i`

`$ node-gyp rebuild`

`$ cp *.so ../`
##### 先修改测试脚本中的账户密码等参数, 然后
`$ node try-mduser.js`

##### 说明1: 注意依赖目录的关系, 运行前, 需要把动态链接库需要复制到上层目录
##### 说明2: 由于未知的大量行情造成的崩溃问题, 行情的通知机制改成了抓取, 我的另一个项目femas-napi是使用通知机制.
