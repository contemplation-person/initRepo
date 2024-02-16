function solution(n) {
  if (n == 1) return 1;
  let arr = [1, n];
  answer = 0;

  while (arr[0] < arr[1]) {
    if (n % arr[0] == 0) {
      arr[1] = n / arr[0];
      answer++;
    }
    arr[0]++;
  }

  if (arr[0] == arr[1]) return answer * 2;
  return answer + (answer - 1);
}

/*user solution

    function solution(n) {
        let ans = 0;
        for (let i = 1; i < Math.sqrt(n); i++)
            if (n%i === 0) ans+=2;

        return Number.isInteger(Math.sqrt(n)) ? ans+1 : ans;
    }
    
 */
