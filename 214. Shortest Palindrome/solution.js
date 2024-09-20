/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    let rev = s.split('').reverse().join('');
   
   // Create a combined string with a special character as separator
   let tmp = s + "#" + rev;

   // Prepare the lps (Longest Prefix Suffix) array
   let n = tmp.length;
   let lps = new Array(n).fill(0);
   let index = 0;

   // Build the lps array using the KMP algorithm
   for (let i = 1; i < n; i++) {
       if (tmp[i] === tmp[index]) {
           lps[i] = lps[i - 1] + 1;
           index++;
       } else {
           index = lps[i - 1];
           while (index > 0 && tmp[index] !== tmp[i]) {
               index = lps[index - 1];
           }
           if (tmp[index] === tmp[i]) {
               index++;
           }
           lps[i] = index;
       }
   }

   // Calculate the part of the string to prepend
   let pos = lps[n - 1];
   let res = s.substring(pos).split('').reverse().join('');

   // Return the final result with the shortest palindrome
   return res + s;
};