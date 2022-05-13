# tinyjson
## json只有六种数据类型
类型 | 形式
--|--|
null | 表示为null
boolean | 表示为true/false
number | 一般的浮点数表示
string | 表示为"..."
array | 表示为[...]
object | 表示为{...}

## json库的功能
### 把JSON文本解析为一个树状数据结构、提供接口访问该数据、把树状数据结构转化为JSON文本（序列化、接口、逆序列化）
### Json提供接口，Value负责实现接口，解析JSON在JsonParse实现，生成Json在JsonGnerator实现