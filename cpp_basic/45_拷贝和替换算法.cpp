/*
	copy算法 将容器内指定范围的元素拷贝到另一容器中
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param dest 目标容器结束迭代器
*/
// copy(iterator beg, iterator end, iterator dest)

/*
	replace算法 将容器内指定范围的旧元素修改为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param oldvalue 旧元素
	@param oldvalue 新元素
*/
// replace(iterator beg, iterator end, oldvalue, newvalue)

/*
	replace_if算法 将容器内指定范围满足条件的元素替换为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param callback函数回调或者谓词(返回Bool类型的函数对象)
	@param oldvalue 新元素
*/
// replace_if(iterator beg, iterator end, _callback, newvalue)

/*
	swap算法 互换两个容器的元素
	@param c1容器1
	@param c2容器2
*/
// swap(container c1, container c2)
