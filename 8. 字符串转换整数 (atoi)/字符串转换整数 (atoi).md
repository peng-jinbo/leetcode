# 字符串转换整数

注意边界问题

正数：result < max_num/10 || (result == max_num/10 && int(str[pos] - '0') <= 7)

​			result = result * 10 + int(str[pos] - '0');

负数：-1 *result > (min_num/10)||(-1 *result == (min_num/10) && int(str[pos] - '0') <= 8)

​			result = result * 10 - int(str[pos] - '0');

