function bucketsort(arr, range_min, range_max) {
  if (arr.length <= 1) {
    return arr;
  }
  if (arr.length < 20) {
    return arr.sort();
  }

  let result = [];
  let numberOfBuckets = Math.ceil(Math.sqrt(arr.length));

  for (let i = 0; i < numberOfBuckets; i++) {
    result.push([]);
  }

  let bucketRange = (range_max - range_min) / numberOfBuckets;

  for (let i = 0; i < arr.length; i++) {

    let bucketIndex = Math.floor((arr[i] - range_min) / bucketRange);

    result[bucketIndex].push(arr[i]);
  }

  let finalResult = []
  for (let i = 0; i < result.length; i++) {
    finalResult = finalResult.concat(bucketsort(result[i], i * bucketRange + range_min, (i+1) * bucketRange + range_min));
  }

  return finalResult;
}


// console.log(bucketsort([0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434], 0.0, 1.0));



// console.log(bucketsort([1,2,3,4,5,6,7,8,9,10,11,12,13,14], 0, 15));


// bucketRange = 0.33333
//
//     0.0        0.333       0.666       1.0
//     [ [       ],  [       ],  [       ]]





// calling bucketsort on large arrays compared to quicksort

let test = [];

for (let i = 0; i < 100000; i++) {
  test.push(Math.random());
}



function quicksort(arr) {
  return arr.sort((a, b) => {
    return a - b;
  });
}


console.time("quicksort: ");
quicksort(test);
console.timeEnd("quicksort: ");


console.time("bucketsort: ");
bucketsort(test, 0.0, 1.0);
console.timeEnd("bucketsort: ");

Array.sort
