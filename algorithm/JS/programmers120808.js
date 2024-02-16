function solution(num1, denom1, num2, denom2) {
  let [sumNum, multi] = [num1 * denom2 + num2 * denom1, denom2 * denom1];

  let devideNum = sumNum < multi ? sumNum : multi;
  for (let i = 2; i <= devideNum; i++) {
    if (i !== 1 && sumNum % i === 0 && multi % i === 0) {
      sumNum /= i;
      multi /= i;
      devideNum = sumNum < multi ? sumNum : multi;
    }
  }
  return [sumNum, multi];
}
