# Sorting algorithms, by me
## there are a bunch of sorting algorithms and files in here, here i explain a few of the algorithms

### bubble sort
#### bubble sort is a sort which looks at items in an array, if item is bigger than the item one location to the right, they get switched around
#### this gets done until there are no switch arounds anymore

### undefined sort
###### this sorting algorithm has been made by myself, it might already exist but i made it as a test thinking it might perform quite well. it's currently really bad but the concept stays the same
##### what the sorting algorithm does is make an array the same size as the inputted array, it then fills it up with zeros (to differentiate it from filled in spaces, this needs a fix soon)
#### then it just starts reading out the source array and puts every thing in the output array, but this is done in a bit of a weird way
#### we use binary search to get the best location for a placement in the array, what we do is look for spaces and only place values if values in the array with a lower index have a lower value than the value we're putting in
#### if there is already a value, we shift the array down one position, not the whole array but just 0 - current position 
#### this makes the array get filled up by elements starting on the right and slowly going further to the left 