let argv1 = "hey";
let name1 = "juha";

function functionTest(name, argv1 = "hello")
{
	console.log(`${name},${argv1}`);
}

functionTest(name1);
functionTest(name1, argv1);