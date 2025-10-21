 # Linear Search Performance Benchmark
 
 ## Analysis
 
![plot](plot.png)
 
 The plotted graph of `T(n)` versus `n` shows a nearly **perfect linear relationship**.
 This confirms that the time complexity of the linear search algorithm is indeed **O(n)**.
 
 **Average constant $(( c_{\text{avg}} ))$**:
 
$( c_{\text{avg}} = 3.93318 \times 10^{-9} \text{ seconds per operation} )$
 
 This constant represents the approximate time taken by one iteration of the linear search on my system.
 
 ### System-Dependent Differences
 
 If this experiment were performed on different machines, the estimated constant ( c ) would likely differ due to:
 
 * **CPU clock speed and architecture**
 * **Cache size and memory latency**
 * **Compiler optimizations and language implementation**
 * **Operating system and background process load**
 
 ## Conclusion
 
 Through this experiment, I empirically verified that the **linear search algorithm** exhibits **O(n)** time complexity, as predicted by asymptotic analysis.
 The measured execution times increased proportionally with the input size, confirming the theoretical linear growth rate.
 
 I also observed that the constant ( c ) representing the time per comparison is approximately **3.93e-9 seconds per operation** on my system.
