let animal = {
  walk() {
    if (!this.isSleeping) {
      console.log(`동물이 걸어갑니다.`);
    }
  },
  sleep() {
    this.isSleeping = true;
  }
};

let rabbit = {
  name: "하얀 토끼",
  __proto__: animal
};

// rabbit에 새로운 프로퍼티 isSleeping을 추가하고 그 값을 true로 변경합니다.
rabbit.sleep();

console.log(rabbit.isSleeping); // true
console.log(animal.isSleeping);
console.log(animal.test);
animal.sleep();
console.log(animal.isSleeping);