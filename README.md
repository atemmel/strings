# strings

```
Benchmark 1 (6795 runs): ./build/linear ./corpus-1 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time           715us ± 81.3us     612us … 1.77ms        142 ( 2%)        0%
  peak_rss           3.78MB ± 47.6KB    3.49MB … 3.95MB        925 (14%)        0%
  cpu_cycles         1.22M  ± 52.8K     1.17M  … 3.28M         809 (12%)        0%
  instructions       2.61M  ± 4.11      2.61M  … 2.61M         418 ( 6%)        0%
  cache_references   55.5K  ± 2.40K     53.1K  …  114K         738 (11%)        0%
  cache_misses       12.5K  ±  783      11.0K  … 17.3K        1039 (15%)        0%
  branch_misses      15.0K  ± 99.5      13.7K  … 15.5K         472 ( 7%)        0%
Benchmark 2 (6694 runs): ./build/boyer-moore ./corpus-1 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time           728us ± 90.7us     605us … 2.47ms        118 ( 2%)        💩+  1.8% ±  0.4%
  peak_rss           3.77MB ± 50.0KB    3.45MB … 3.94MB        980 (15%)          -  0.0% ±  0.0%
  cpu_cycles         1.21M  ± 71.5K     1.15M  … 3.11M         811 (12%)          -  0.9% ±  0.2%
  instructions       2.57M  ± 3.90      2.57M  … 2.57M         461 ( 7%)        ⚡-  1.8% ±  0.0%
  cache_references   55.7K  ± 2.90K     53.5K  …  109K         750 (11%)          +  0.5% ±  0.2%
  cache_misses       12.6K  ±  879      11.1K  … 19.1K         740 (11%)          +  0.7% ±  0.2%
  branch_misses      14.8K  ±  106      13.2K  … 15.3K         460 ( 7%)        ⚡-  1.5% ±  0.0%
Benchmark 3 (4726 runs): ./build/threaded ./corpus-1 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          1.04ms ±  138us     835us … 3.43ms         73 ( 2%)        💩+ 44.8% ±  0.6%
  peak_rss           3.99MB ± 85.7KB    3.57MB … 4.07MB         46 ( 1%)        💩+  5.6% ±  0.1%
  cpu_cycles         1.39M  ± 91.8K     1.31M  … 3.01M         410 ( 9%)        💩+ 13.8% ±  0.2%
  instructions       2.69M  ± 87.3      2.68M  … 2.69M        1552 (33%)        💩+  2.8% ±  0.0%
  cache_references   75.2K  ± 2.81K     66.5K  …  126K         259 ( 5%)        💩+ 35.6% ±  0.2%
  cache_misses       18.1K  ± 1.51K     14.6K  … 27.2K         125 ( 3%)        💩+ 44.4% ±  0.3%
  branch_misses      16.5K  ±  149      15.1K  … 17.1K          84 ( 2%)        💩+  9.9% ±  0.0%
```

```
Benchmark 1 (2519 runs): ./build/linear ./corpus-2 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          1.96ms ±  155us    1.59ms … 2.64ms         19 ( 1%)        0%
  peak_rss           4.59MB ± 91.7KB    4.24MB … 4.73MB          1 ( 0%)        0%
  cpu_cycles         4.97M  ±  182K     4.71M  … 7.34M         420 (17%)        0%
  instructions       11.3M  ± 3.92      11.3M  … 11.3M         429 (17%)        0%
  cache_references   79.5K  ± 6.15K     73.8K  …  136K         273 (11%)        0%
  cache_misses       13.8K  ±  851      12.2K  … 19.5K         217 ( 9%)        0%
  branch_misses      50.9K  ± 4.29K     40.9K  … 55.4K          33 ( 1%)        0%
Benchmark 2 (3547 runs): ./build/boyer-moore ./corpus-2 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          1.39ms ±  121us    1.18ms … 1.96ms         38 ( 1%)        ⚡- 29.2% ±  0.4%
  peak_rss           4.61MB ± 81.5KB    4.23MB … 4.73MB          7 ( 0%)          +  0.6% ±  0.1%
  cpu_cycles         2.56M  ± 33.1K     2.49M  … 2.90M          93 ( 3%)        ⚡- 48.5% ±  0.1%
  instructions       4.39M  ± 3.56      4.39M  … 4.39M         375 (11%)        ⚡- 61.0% ±  0.0%
  cache_references   79.6K  ± 6.21K     73.4K  …  139K          69 ( 2%)          +  0.2% ±  0.4%
  cache_misses       13.7K  ±  801      12.2K  … 18.4K         305 ( 9%)          -  1.1% ±  0.3%
  branch_misses      17.3K  ±  769      14.9K  … 19.4K           0 ( 0%)        ⚡- 66.1% ±  0.3%
Benchmark 3 (3100 runs): ./build/threaded ./corpus-2 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          1.59ms ±  129us    1.32ms … 2.80ms         32 ( 1%)        ⚡- 19.0% ±  0.4%
  peak_rss           4.80MB ±  122KB    4.35MB … 4.95MB        159 ( 5%)        💩+  4.8% ±  0.1%
  cpu_cycles         12.0M  ±  472K     9.76M  … 14.2M          49 ( 2%)        💩+142.0% ±  0.4%
  instructions       20.0M  ±  241      20.0M  … 20.0M          49 ( 2%)        💩+ 77.8% ±  0.0%
  cache_references    119K  ± 3.21K      114K  …  173K         140 ( 5%)        💩+ 49.9% ±  0.3%
  cache_misses       20.1K  ± 1.06K     17.7K  … 26.1K         164 ( 5%)        💩+ 45.2% ±  0.4%
  branch_misses      97.2K  ±  617      93.8K  … 99.7K         119 ( 4%)        💩+ 90.9% ±  0.3%
```

```
Benchmark 1 (503 runs): ./build/linear ./corpus-3 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          9.91ms ±  905us    7.00ms … 12.6ms          8 ( 2%)        0%
  peak_rss           14.0MB ±  118KB    13.7MB … 14.2MB          3 ( 1%)        0%
  cpu_cycles         32.2M  ± 1.34M     27.4M  … 40.7M          78 (16%)        0%
  instructions       72.3M  ± 6.24      72.3M  … 72.3M          30 ( 6%)        0%
  cache_references    252K  ± 18.3K      208K  …  320K           1 ( 0%)        0%
  cache_misses       15.0K  ± 1.02K     13.2K  … 18.9K          52 (10%)        0%
  branch_misses       301K  ± 37.5K      107K  …  321K          70 (14%)        0%
Benchmark 2 (801 runs): ./build/boyer-moore ./corpus-3 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          6.22ms ±  693us    3.65ms … 8.10ms         56 ( 7%)        ⚡- 37.2% ±  0.9%
  peak_rss           14.0MB ±  130KB    13.7MB … 14.2MB          0 ( 0%)          -  0.0% ±  0.1%
  cpu_cycles         12.2M  ±  228K     11.8M  … 13.2M          31 ( 4%)        ⚡- 62.0% ±  0.3%
  instructions       17.3M  ± 5.13      17.3M  … 17.3M          32 ( 4%)        ⚡- 76.1% ±  0.0%
  cache_references    240K  ± 17.5K      207K  …  291K           1 ( 0%)        ⚡-  4.7% ±  0.8%
  cache_misses       14.8K  ±  986      13.0K  … 19.8K          80 (10%)          -  1.2% ±  0.7%
  branch_misses      24.7K  ± 2.69K     19.7K  … 33.9K         181 (23%)        ⚡- 91.8% ±  0.9%
Benchmark 3 (750 runs): ./build/threaded ./corpus-3 afternoon
  measurement          mean ± σ            min … max           outliers         delta
  wall_time          6.64ms ±  790us    3.85ms … 9.10ms         36 ( 5%)        ⚡- 33.0% ±  1.0%
  peak_rss           14.1MB ±  137KB    13.7MB … 14.3MB          0 ( 0%)          +  0.3% ±  0.1%
  cpu_cycles          108M  ± 3.63M     88.1M  …  115M          39 ( 5%)        💩+235.7% ±  1.0%
  instructions        151M  ±  143       151M  …  151M           9 ( 1%)        💩+108.6% ±  0.0%
  cache_references    444K  ± 31.3K      401K  …  553K          38 ( 5%)        💩+ 76.2% ±  1.2%
  cache_misses       24.0K  ± 1.31K     21.5K  … 29.4K          32 ( 4%)        💩+ 59.7% ±  0.9%
  branch_misses       672K  ± 4.54K      639K  …  683K          75 (10%)        💩+123.4% ±  0.9%
```
