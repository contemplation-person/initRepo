global = "test";
console.log(global);
var global;

// local = "test";  안됨
let local;
local = "local";
console.log(local);

// const는 객체 자체를 바꾸는 것이 아니라 객체의 내용을 바꾸는 것이기 때문에 허용
const obj = {a : 1};
obj.a = 5;
console.log(obj.a);