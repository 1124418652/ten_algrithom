# -*- coding: utf-8 -*-


def maxAddSub_violent(a):
	"""
	使用暴力法求解序列中累加和最大的子序列，用i固定子序列的
	头，用j固定子序列的尾，用k在子序列中滑动进行累加，求解
	当前序列的累加和。
	
	时间复杂度为 O(n^3)

	Arguments:
	a -- 输入的一维数组

	Returns:
	max_sum_array -- 从输入数组中选出的累加和最大的连续数组
	"""

	length = len(a)
	max_sum_array = a[0]
	curr_sum_array = 0

	for i in range(0, length):
		for j in range(i, length):
			curr_sum_array = 0
			
			for k in range(i, j + 1):
				curr_sum_array += a[k]
			if curr_sum_array >= max_sum_array:
				max_sum_array = curr_sum_array

	return max_sum_array 

def maxAddSub_divide(a, begin, end):
	"""
	使用分治法求解序列中累加和最大的子序列。将数组从中间分开，
	那么最大子数组要么完全在左半边数组，要么完全在右半边数组，
	要么跨立在分解点上。
	1、完全在左数组、右数组时递归解决。
	2、跨立在分界点上：实际上是左数组的最大后缀和右数组的最大前
	   缀之和。因此，从分界点向前扫，向后扫即可。
	
	算法复杂度分析：
	时间复杂度的递推关系：T(n) = 2 * T(n/2) + c*n, c为常数
	若 n=2^k，则通过递推求解可以得到：T(n) = T(1)*n + c*n*log_2(n)
	时间复杂度为：O(nlogn)
	

	Arguments:
	a -- 输入的一维数组，完整的数组
	begin -- 输入数组的起始位置
	end -- 输入数组的结束位置，n-1

	Returns:
	max_sum_array -- 从输入数组中选出的累加和最大的连续数组
	"""

	if end == begin:
		return a[begin]

	middle = (begin + end) // 2   # 求解输入的部分序列的中间位置
	m1 = maxAddSub_divide(a, begin, middle)     # 递归求解左数组中的最大累加和
	m2 = maxAddSub_divide(a, middle + 1, end)   # 递归求解右数组中的最大累加和

	# 求左侧数组的最大后缀
	left_max = a[middle]
	tmp = a[middle]        # 用于计算累加的临时变量
	for i in range(middle - 1, begin -1, -1):  # 从后往前遍历，每走一步判断一次是否为最大
		tmp += a[i]
		left_max = max(left_max, tmp)

	# 求右侧数组的最大前缀
	right_max = a[middle + 1]
	tmp = a[middle + 1]
	for i in range(middle + 2, end + 1):  # 注意要能取到 end，所以尾为 end + 1
		tmp += a[i]
		right_max = max(right_max, tmp)

	# 计算跨立分界点时的最大累加和 = left_max + right_max
	m3 = left_max + right_max
	return max(m1, m2, m3)    # 返回当前递归层的最大累加和

def maxAddSub_analysis(a):
	"""
	使用分析法求解序列中累加和最大的子序列。
	"""


if __name__ == '__main__':
	a = [1, 2, 4, 5, -6, 9, 2, -2, 10]
	print(maxAddSub_divide(a, 0, len(a) - 1))
	print(maxAddSub_violent(a))
