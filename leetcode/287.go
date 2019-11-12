package main

import "fmt"

func findDuplicate(nums []int) int {
	fast := 0
	slow := 0
	for true {
		fast = nums[nums[fast]]
		slow = nums[slow]
		if fast == slow {
			break
		}
	}
	finder := 0
	for true {
		finder = nums[finder]
		slow = nums[slow]
		if finder == slow {
			break
		}
	}
	return slow

}

func main() {
	nums := []int{1, 2, 3, 4, 5, 1}
	fmt.Println(findDuplicate(nums))
}
