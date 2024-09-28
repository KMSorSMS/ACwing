Object.assign(window.search, {"doc_urls":["basic/note1.html#basic-part","basic/note1.html#排序","basic/note1.html#785-quiksort-786-select_quicksort","basic/note1.html#787-merge_sort-788-reverse_pairs","basic/note1.html#二分","basic/note1.html#789_number_range-790-cubic_equation"],"index":{"documentStore":{"docInfo":{"0":{"body":0,"breadcrumbs":4,"title":2},"1":{"body":0,"breadcrumbs":2,"title":0},"2":{"body":3,"breadcrumbs":6,"title":4},"3":{"body":0,"breadcrumbs":6,"title":4},"4":{"body":0,"breadcrumbs":2,"title":0},"5":{"body":2,"breadcrumbs":5,"title":3}},"docs":{"0":{"body":"","breadcrumbs":"basic-first20 » basic part","id":"0","title":"basic part"},"1":{"body":"","breadcrumbs":"basic-first20 » 排序","id":"1","title":"排序"},"2":{"body":"最重要的是边界的思考，和对于比较点的选择： 每次无论左边还是右边的移动找可交换点，都应该不包含等于边界点的情况，因为如果跳过，那么就会出现死循环的情况，比如132，left从1开始一直移动到2，right会保持到2，那么就会一直卡在这个循环（在选择比较点为中点的情况），对于比较点的值，就算作left和right共同的分界线点，会进行交换. 写的时候记得几个特殊情况：1332，这会让left和right都停在3,所以if判断需要涵盖left==right的情况，并且以选取right作为分隔，这是因为除法的向下取整的原因，这里不能把left作为分界（除非向上取整，模板改成p[(left + right+1) >> 1];） select 快排只是变形，我们找第K小的数只需要去除不必要的递归，因为每次递归会缩小区间，只需要递归第K小的数所在的区间即可","breadcrumbs":"basic-first20 » 785-QuikSort 786-Select_QuickSort","id":"2","title":"785-QuikSort 786-Select_QuickSort"},"3":{"body":"归并排序，分治法的典型应用，需要注意的是，归并排序的时间复杂度是O(nlogn),空间复杂度是O(n),因为需要一个额外的数组来存储排序后的结果，所以在空间复杂度上不如快排，但是在稳定性上要好于快排.这里细节上比快排简单，分界点取到mid，因为向下取整的原因，要分成[left,mid]，[mid+1,right]两个区间,不然12的时候是死循环。然后分成合并两个递归后保证了大小顺序的区间，最后记得复制结果到原始数组，因为递归返回后还会使用这个结果。 寻找逆序对这里是一个简单的变形，因为要找到所有的逆序对，那么就分成一小段一小段找，和找第K大的数类似，因为对于排好序的区间，那么内部不存在逆序，只能是前一半区间对后一半区间可能存在有逆序对，这样就能先分割为小区间，然后再合并的时候找逆序对（从最小的，元素数量为1的区间开始左右合并），就能找完所有的逆序对。","breadcrumbs":"basic-first20 » 787-merge_sort 788 reverse_pairs","id":"3","title":"787-merge_sort 788 reverse_pairs"},"4":{"body":"","breadcrumbs":"basic-first20 » 二分","id":"4","title":"二分"},"5":{"body":"分别去找下界和上界找下界时，mid向下取整，主要是考虑12情况（找1），这个时候mid如果是1，那么right就会一直为1，所以要向下取整，这样mid就会为0。同样，找上界时，应该向上取整，比如12（找1），这个时候如果mid是0，那么left就会一直为0，所以要向上取整，这样mid就会为1。本质来说，之所以死循环，是前一次的mid和后一次的mid是一样的，也就是left、right没有移动，找上界时，进行向上取整就是因为上界的<=判定是移动left到mid，因为向上取整，所以mid是不可能等于left的，所以不会出现死循环的情况。对于找下界，道理是一样的。 解三次方程，就是在范围内找mid的三次方最接近target的值，这里的mid是double类型，所以要注意精度问题，还有范围，开三次方的范围一般是-|n|到|n|,但是对于小于1的来说，它的范围应该是-1到1，然后在里面用二分法，一直找mid，直到精度满足要求。","breadcrumbs":"basic-first20 » 789_number_range 790-cubic_equation","id":"5","title":"789_number_range 790-cubic_equation"}},"length":6,"save":true},"fields":["title","body","breadcrumbs"],"index":{"body":{"root":{"1":{"df":1,"docs":{"2":{"tf":1.0}},"到":{"1":{"df":0,"docs":{},"，":{"df":0,"docs":{},"然":{"df":0,"docs":{},"后":{"df":0,"docs":{},"在":{"df":0,"docs":{},"里":{"df":0,"docs":{},"面":{"df":0,"docs":{},"用":{"df":0,"docs":{},"二":{"df":0,"docs":{},"分":{"df":0,"docs":{},"法":{"df":0,"docs":{},"，":{"df":0,"docs":{},"一":{"df":0,"docs":{},"直":{"df":0,"docs":{},"找":{"df":0,"docs":{},"m":{"df":0,"docs":{},"i":{"d":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}}}}}}}}}}}}}}}}}},"df":0,"docs":{}}},"7":{"8":{"5":{"df":1,"docs":{"2":{"tf":1.0}}},"6":{"df":1,"docs":{"2":{"tf":1.0}}},"7":{"df":1,"docs":{"3":{"tf":1.0}}},"8":{"df":1,"docs":{"3":{"tf":1.0}}},"9":{"_":{"df":0,"docs":{},"n":{"df":0,"docs":{},"u":{"df":0,"docs":{},"m":{"b":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"_":{"df":0,"docs":{},"r":{"a":{"df":0,"docs":{},"n":{"df":0,"docs":{},"g":{"df":1,"docs":{"5":{"tf":1.0}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}},"df":0,"docs":{}}}}},"df":0,"docs":{}},"df":0,"docs":{}},"9":{"0":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}},"df":0,"docs":{}},"b":{"a":{"df":0,"docs":{},"s":{"df":0,"docs":{},"i":{"c":{"df":1,"docs":{"0":{"tf":1.0}}},"df":0,"docs":{}}}},"df":0,"docs":{}},"c":{"df":0,"docs":{},"u":{"b":{"df":0,"docs":{},"i":{"c":{"_":{"df":0,"docs":{},"e":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":1,"docs":{"5":{"tf":1.0}}}}}},"df":0,"docs":{}},"df":0,"docs":{}}},"df":0,"docs":{}}},"df":0,"docs":{},"m":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"g":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"3":{"tf":1.0}}}}}}},"df":0,"docs":{}}}}}},"n":{"df":0,"docs":{},"|":{"df":0,"docs":{},"到":{"df":0,"docs":{},"|":{"df":0,"docs":{},"n":{"df":0,"docs":{},"|":{",":{"df":0,"docs":{},"但":{"df":0,"docs":{},"是":{"df":0,"docs":{},"对":{"df":0,"docs":{},"于":{"df":0,"docs":{},"小":{"df":0,"docs":{},"于":{"1":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}}}}}}}},"df":0,"docs":{}}}}}}},"p":{"a":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"0":{"tf":1.0}}}}},"df":0,"docs":{}},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.0}}}}}}}}}},"r":{"df":0,"docs":{},"e":{"df":0,"docs":{},"v":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"s":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"p":{"a":{"df":0,"docs":{},"i":{"df":0,"docs":{},"r":{"df":1,"docs":{"3":{"tf":1.0}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}}}}},"i":{"df":0,"docs":{},"g":{"df":0,"docs":{},"h":{"df":0,"docs":{},"t":{"+":{"1":{"df":1,"docs":{"2":{"tf":1.0}}},"df":0,"docs":{}},"df":0,"docs":{}}}}}},"s":{"df":0,"docs":{},"e":{"df":0,"docs":{},"l":{"df":0,"docs":{},"e":{"c":{"df":0,"docs":{},"t":{"_":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"c":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.0}}}}}}}},"df":0,"docs":{}}}}},"df":1,"docs":{"2":{"tf":1.0}}}},"df":0,"docs":{}}}}}}},"breadcrumbs":{"root":{"1":{"df":1,"docs":{"2":{"tf":1.0}},"到":{"1":{"df":0,"docs":{},"，":{"df":0,"docs":{},"然":{"df":0,"docs":{},"后":{"df":0,"docs":{},"在":{"df":0,"docs":{},"里":{"df":0,"docs":{},"面":{"df":0,"docs":{},"用":{"df":0,"docs":{},"二":{"df":0,"docs":{},"分":{"df":0,"docs":{},"法":{"df":0,"docs":{},"，":{"df":0,"docs":{},"一":{"df":0,"docs":{},"直":{"df":0,"docs":{},"找":{"df":0,"docs":{},"m":{"df":0,"docs":{},"i":{"d":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}}}}}}}}}}}}}}}}}},"df":0,"docs":{}}},"7":{"8":{"5":{"df":1,"docs":{"2":{"tf":1.4142135623730951}}},"6":{"df":1,"docs":{"2":{"tf":1.4142135623730951}}},"7":{"df":1,"docs":{"3":{"tf":1.4142135623730951}}},"8":{"df":1,"docs":{"3":{"tf":1.4142135623730951}}},"9":{"_":{"df":0,"docs":{},"n":{"df":0,"docs":{},"u":{"df":0,"docs":{},"m":{"b":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"_":{"df":0,"docs":{},"r":{"a":{"df":0,"docs":{},"n":{"df":0,"docs":{},"g":{"df":1,"docs":{"5":{"tf":1.4142135623730951}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}},"df":0,"docs":{}}}}},"df":0,"docs":{}},"df":0,"docs":{}},"9":{"0":{"df":1,"docs":{"5":{"tf":1.4142135623730951}}},"df":0,"docs":{}},"df":0,"docs":{}},"b":{"a":{"df":0,"docs":{},"s":{"df":0,"docs":{},"i":{"c":{"df":6,"docs":{"0":{"tf":1.7320508075688772},"1":{"tf":1.0},"2":{"tf":1.0},"3":{"tf":1.0},"4":{"tf":1.0},"5":{"tf":1.0}}},"df":0,"docs":{}}}},"df":0,"docs":{}},"c":{"df":0,"docs":{},"u":{"b":{"df":0,"docs":{},"i":{"c":{"_":{"df":0,"docs":{},"e":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":1,"docs":{"5":{"tf":1.4142135623730951}}}}}},"df":0,"docs":{}},"df":0,"docs":{}}},"df":0,"docs":{}}},"df":0,"docs":{},"f":{"df":0,"docs":{},"i":{"df":0,"docs":{},"r":{"df":0,"docs":{},"s":{"df":0,"docs":{},"t":{"2":{"0":{"df":6,"docs":{"0":{"tf":1.0},"1":{"tf":1.0},"2":{"tf":1.0},"3":{"tf":1.0},"4":{"tf":1.0},"5":{"tf":1.0}}},"df":0,"docs":{}},"df":0,"docs":{}}}}}},"m":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"g":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"3":{"tf":1.4142135623730951}}}}}}},"df":0,"docs":{}}}}}},"n":{"df":0,"docs":{},"|":{"df":0,"docs":{},"到":{"df":0,"docs":{},"|":{"df":0,"docs":{},"n":{"df":0,"docs":{},"|":{",":{"df":0,"docs":{},"但":{"df":0,"docs":{},"是":{"df":0,"docs":{},"对":{"df":0,"docs":{},"于":{"df":0,"docs":{},"小":{"df":0,"docs":{},"于":{"1":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}}}}}}}},"df":0,"docs":{}}}}}}},"p":{"a":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"0":{"tf":1.4142135623730951}}}}},"df":0,"docs":{}},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.4142135623730951}}}}}}}}}},"r":{"df":0,"docs":{},"e":{"df":0,"docs":{},"v":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"s":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"p":{"a":{"df":0,"docs":{},"i":{"df":0,"docs":{},"r":{"df":1,"docs":{"3":{"tf":1.4142135623730951}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}}}}},"i":{"df":0,"docs":{},"g":{"df":0,"docs":{},"h":{"df":0,"docs":{},"t":{"+":{"1":{"df":1,"docs":{"2":{"tf":1.0}}},"df":0,"docs":{}},"df":0,"docs":{}}}}}},"s":{"df":0,"docs":{},"e":{"df":0,"docs":{},"l":{"df":0,"docs":{},"e":{"c":{"df":0,"docs":{},"t":{"_":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"c":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.4142135623730951}}}}}}}},"df":0,"docs":{}}}}},"df":1,"docs":{"2":{"tf":1.0}}}},"df":0,"docs":{}}}}}}},"title":{"root":{"7":{"8":{"5":{"df":1,"docs":{"2":{"tf":1.0}}},"6":{"df":1,"docs":{"2":{"tf":1.0}}},"7":{"df":1,"docs":{"3":{"tf":1.0}}},"8":{"df":1,"docs":{"3":{"tf":1.0}}},"9":{"_":{"df":0,"docs":{},"n":{"df":0,"docs":{},"u":{"df":0,"docs":{},"m":{"b":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"_":{"df":0,"docs":{},"r":{"a":{"df":0,"docs":{},"n":{"df":0,"docs":{},"g":{"df":1,"docs":{"5":{"tf":1.0}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}},"df":0,"docs":{}}}}},"df":0,"docs":{}},"df":0,"docs":{}},"9":{"0":{"df":1,"docs":{"5":{"tf":1.0}}},"df":0,"docs":{}},"df":0,"docs":{}},"b":{"a":{"df":0,"docs":{},"s":{"df":0,"docs":{},"i":{"c":{"df":1,"docs":{"0":{"tf":1.0}}},"df":0,"docs":{}}}},"df":0,"docs":{}},"c":{"df":0,"docs":{},"u":{"b":{"df":0,"docs":{},"i":{"c":{"_":{"df":0,"docs":{},"e":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":1,"docs":{"5":{"tf":1.0}}}}}},"df":0,"docs":{}},"df":0,"docs":{}}},"df":0,"docs":{}}},"df":0,"docs":{},"m":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"g":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"3":{"tf":1.0}}}}}}},"df":0,"docs":{}}}}}},"p":{"a":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"0":{"tf":1.0}}}}},"df":0,"docs":{}},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.0}}}}}}}}}},"r":{"df":0,"docs":{},"e":{"df":0,"docs":{},"v":{"df":0,"docs":{},"e":{"df":0,"docs":{},"r":{"df":0,"docs":{},"s":{"df":0,"docs":{},"e":{"_":{"df":0,"docs":{},"p":{"a":{"df":0,"docs":{},"i":{"df":0,"docs":{},"r":{"df":1,"docs":{"3":{"tf":1.0}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}}}}}},"s":{"df":0,"docs":{},"e":{"df":0,"docs":{},"l":{"df":0,"docs":{},"e":{"c":{"df":0,"docs":{},"t":{"_":{"df":0,"docs":{},"q":{"df":0,"docs":{},"u":{"df":0,"docs":{},"i":{"c":{"df":0,"docs":{},"k":{"df":0,"docs":{},"s":{"df":0,"docs":{},"o":{"df":0,"docs":{},"r":{"df":0,"docs":{},"t":{"df":1,"docs":{"2":{"tf":1.0}}}}}}}},"df":0,"docs":{}}}}},"df":0,"docs":{}}},"df":0,"docs":{}}}}}}}},"lang":"English","pipeline":["trimmer","stopWordFilter","stemmer"],"ref":"id","version":"0.9.5"},"results_options":{"limit_results":30,"teaser_word_count":30},"search_options":{"bool":"OR","expand":true,"fields":{"body":{"boost":1},"breadcrumbs":{"boost":1},"title":{"boost":2}}}});