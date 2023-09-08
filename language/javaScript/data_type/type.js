//string, number, bigint, boolean, undefined, null, symbol 이 원시 타입
let num1 = 123; // number
let num2 = 2; // number
let str1 = "test"; //str
let str2 = " is string"; // string
let operator = `+`;

console.log(`${str1}${str2}`); // 백틱은 변수를 변환해준다.
console.log("${str1}${str2}");
console.log(`${num1}${operator}${num2}`); // 숫자 연산은 안된다.
//const obj = { a: 3 };
//obj = { b: 5 } // not allowed
//obj.b = 5; 
//console.table(obj);
let bool = true;
console.log(bool);
if(undefined) {
	console.log("WTF");
}
console.log(1 === "1");
console.log(undefined === null);
console.log(null == "");
