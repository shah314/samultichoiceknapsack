<H1>Simulated Annealing Algorithm for the Multiple Choice Multidimensional Knapsack Problem</H1>

<i><h3>Shalin Shah</h3></i>
<a href="https://zenodo.org/badge/latestdoi/134318963"><img src="https://zenodo.org/badge/134318963.svg" alt="DOI"></a>

<P>Implementation of simulated annealing algorithm for the multiple choice  multidimensional knapsack problem. The multiple choice knapsack problem has <I>n</I> groups of items and <I>m</I> constraints. The objective is to choose one item from each group such that the total value (profit) is maximized while all of the m constraints are satisfied. </P>

<P>Change the global variable ANNEALING_ITERATIONS to change the number of iterations that the algorithm runs for.</P>
<P>Instances are available at the following FTP site and also in the instances folder (please rename an instance to data.dat so that the algorithm can find it):<br>
ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/</p>
<P>Usage:<BR>The algorithm requires a "data.dat" file in the current directory in the format specified by:<br>
ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/MMKP.html</P>
<br>
<b>Cite this code:</b>
<pre>
@misc{shah2014mcknapsack,
  title={Simulated Annealing Algorithm for the Multiple Choice Multidimensional Knapsack Problem},
  author={Shah, Shalin},
  year={2014}
}
</pre>
<b>Cited By:</b>
<ul>
  <li>Heikal, A. F., et al. "A New Genetic Algorithm for Multiple-Choice Multidimensional Knapsack Problem." The International Conference on Electrical Engineering. Vol. 7. No. 7th International Conference on Electrical Engineering ICEENG 2010. Military Technical College, 2010.</li>
</ul><br>
<p>The solutions found by the algorithm to these instances:<br>
(The code is run for 100000 iterations)</P>
<pre>
<b>I01:
</b>Objective Function: 173
Solution:
3 4 1 2 3

<b>I02:
</b>Objective Function: 364
Solution:
4 4 3 3 4 3 2 0 2 3

<b>I03:
</b>Objective Function: 1600
Solution:
2 5 9 9 4 5 7 2 9 3 9 8 9 9 9

<b>I04:
</b>Objective Function: 3580
Solution:
4 9 9 6 9 8 9 2 6 9 4 7 4 9 8 8 8 6 1 8

<b>I05:
</b>Objective Function: 3900 (3905 with floating point calculations)
Solution: 
9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  9  8

<b>I06:
</b>Objective Function: 4792 (4799.30 with floating point calculations)
Solution:
9 9 9 9 8 8 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 8 9 9 9 9 9

<b>I07:
</b>Objective Function: 24151
Solution:
7 9 9 9 8 7 7 7 9 3 4 0 9 2 2 9 5 2 2 8 3 7 8 9 5 9 2 0 9 9 9 8 9 9 8 6 0 8 1 7
8 4 8 5 8 9 8 8 9 9 0 8 7 8 9 5 6 9 5 8 5 6 7 9 8 7 2 9 7 9 9 9 8 9 7 1 9 8 9 7
8 8 8 5 6 7 5 9 9 7 9 6 2 9 1 8 9 8 9 4

<b>I08:
</b>Objective Function: 36305
Solution:
9 9 9 3 8 8 7 6 9 1 4 0 9 9 8 9 4 2 1 6 9 6 8 9 9 6 2 9 8 1 4 9 5 6 8 7 9 9 1 9
5 0 9 9 9 5 6 3 9 0 7 9 7 9 9 4 9 9 5 3 9 1 3 8 0 7 9 9 7 9 9 7 8 0 3 8 9 9 6 7
4 7 8 5 1 9 9 7 9 9 9 7 9 0 1 8 9 8 8 8 4 0 7 9 5 9 5 9 4 8 7 9 7 5 9 8 9 9 8 9
8 7 8 9 7 3 7 9 9 7 5 9 8 1 8 8 4 8 9 9 7 9 2 9 7 6 3 4 7 6

<b>I09:
</b>Objective Function: 48298
Solution:
3 9 9 5 8 8 2 9 2 3 4 0 7 8 8 9 7 4 5 2 5 6 4 9 9 7 9 9 9 9 4 9 5 9 8 9 6 8 1 7
9 7 3 9 4 5 6 8 4 8 7 9 8 9 9 5 7 9 8 6 9 9 4 8 6 9 2 9 7 7 9 8 8 9 9 8 9 8 7 9
8 9 8 7 7 8 9 9 4 7 4 9 6 9 1 4 9 8 5 8 9 6 2 9 9 5 9 1 0 3 7 9 2 7 5 8 9 3 1 9
7 0 2 0 9 7 7 9 8 1 5 9 8 7 8 8 4 8 9 9 7 5 2 9 4 8 8 9 5 9 9 3 7 9 6 7 5 8 5 9
4 9 0 7 9 6 1 2 9 0 7 9 3 6 0 7 9 5 9 2 9 2 9 6 8 0 9 9 9 9 7 6 7 2 7 9 3 7 9 9

<b>I10:
</b>Objective Function: 60194
Solution:
9 9 9 8 7 7 8 9 9 9 9 1 7 8 8 6 4 3 8 8 9 7 3 9 7 9 9 0 9 9 9 8 7 9 8 1 2 9 1 7
8 7 8 0 7 9 6 8 9 8 7 9 8 2 2 7 9 7 5 5 9 6 5 8 1 8 2 1 7 9 8 8 9 3 8 9 9 1 7 9
8 7 4 5 6 9 9 8 2 7 9 9 8 3 1 9 9 8 2 8 4 2 9 9 5 5 9 9 7 0 7 0 2 2 2 1 9 9 6 9
0 6 8 3 8 7 2 9 9 7 5 8 9 1 9 9 8 1 9 9 7 9 9 4 8 6 5 4 7 6 9 3 4 7 9 8 5 9 6 8
6 9 8 7 3 9 9 6 7 0 9 1 7 7 6 9 9 8 8 9 9 3 9 7 5 9 9 9 7 5 8 6 7 9 2 9 8 8 9 0
5 5 7 5 7 1 8 9 3 9 7 8 2 4 9 9 7 9 4 7 2 6 7 9 7 8 5 6 7 8 9 7 6 2 8 4 8 9 7 7
8 8 9 8 7 0 3 9 9 8

<b>I11:
</b>Objective Function: 72474
Solution:
9 9 0 5 8 7 7 7 9 9 9 0 9 9 8 9 7 5 8 8 3 5 6 1 9 5 9 9 9 8 3 8 6 8 8 5 9 8 1 4
9 9 3 9 9 8 9 9 9 0 7 9 8 8 9 5 9 9 5 3 9 1 7 8 6 7 5 9 1 9 9 6 8 9 9 9 9 4 7 9
9 9 8 7 6 7 9 9 8 9 9 9 6 0 1 7 9 8 2 6 4 6 6 9 9 5 9 1 9 9 7 0 7 5 5 8 9 9 9 9
8 6 3 9 8 7 9 9 9 7 5 9 6 1 8 5 9 9 3 9 1 9 9 9 9 6 4 9 5 6 3 7 8 9 7 7 8 9 6 8
9 9 8 8 9 5 9 2 7 4 8 9 9 7 5 9 9 1 9 2 9 5 5 9 2 9 7 1 9 9 9 6 7 9 7 9 3 8 9 7
9 5 9 9 7 8 6 9 3 9 8 4 2 5 0 7 7 9 7 7 7 0 2 9 4 9 7 9 9 8 9 7 7 9 5 9 8 9 7 9
8 9 1 4 1 8 3 9 1 8 6 1 5 8 9 7 9 8 7 8 3 7 8 5 9 4 7 8 8 2 8 9 2 1 9 9 4 5 7 8
6 4 6 2 1 2 0 9 9 9 9 8 7 9 0 8 9 3 5 0

<b>I12:
</b>Objective Function: 84585
Solution:
9 9 0 9 3 7 7 9 9 8 4 0 9 8 8 8 7 4 8 2 5 7 8 0 9 4 9 9 5 9 9 9 5 9 8 9 9 8 8 1
6 7 9 5 1 3 6 9 2 8 7 9 4 7 9 8 8 9 5 0 9 9 7 9 7 7 1 9 7 9 9 8 8 9 3 8 9 8 9 4
7 9 8 7 6 9 7 9 8 7 9 9 6 5 9 1 7 8 9 9 9 9 0 7 7 9 9 7 6 6 7 0 9 5 8 8 8 3 9 9
8 6 9 3 8 8 7 9 4 1 5 9 4 1 8 8 4 4 9 9 7 9 9 9 8 6 8 4 7 6 9 3 8 9 9 6 5 8 5 7
4 9 4 7 9 8 8 9 8 9 7 1 9 7 9 9 9 1 6 9 9 6 5 9 5 5 7 9 9 9 9 6 6 2 7 5 4 8 4 9
4 2 7 9 7 8 9 9 3 9 3 8 0 5 4 6 7 9 9 3 9 6 9 9 4 6 1 6 9 8 9 7 7 4 8 9 9 9 7 9
9 7 5 4 5 0 9 9 1 8 9 7 4 4 9 1 9 9 0 5 9 9 8 8 0 5 8 7 8 2 9 1 2 7 3 9 9 9 7 1
9 8 2 2 1 1 8 9 9 8 5 8 7 9 8 8 2 6 9 8 8 9 8 9 7 9 8 7 1 9 5 1 8 9 9 9 7 9 8 1
8 4 8 8 9 6 9 9 8 6 9 9 0 5 4 9 7 9 4 6 2 7 0 8 8 4 9 9 8 9

<b>I13:
</b>Objective Function: 96679
Solution:
7 7 9 9 8 8 2 9 2 0 5 0 7 9 8 6 7 2 5 0 9 7 8 4 9 5 9 9 2 7 4 8 9 6 8 9 9 9 9 8
8 7 8 5 7 5 9 8 6 8 9 9 7 8 9 9 9 2 7 0 9 6 8 8 9 4 9 9 7 6 9 9 8 9 9 8 5 6 6 9
8 7 9 7 9 9 9 9 2 7 9 9 6 0 1 8 9 9 9 9 4 4 8 7 7 7 9 9 6 0 7 0 2 7 9 8 8 8 9 9
9 7 9 9 1 3 2 9 2 7 9 2 9 9 8 6 4 9 5 9 9 9 9 9 8 8 9 4 8 6 9 7 7 9 1 0 5 6 4 9
9 9 8 4 9 8 1 9 9 9 7 9 9 4 1 8 9 9 6 9 9 2 5 0 8 9 7 9 0 3 7 6 7 9 7 5 8 8 9 9
3 8 9 8 7 1 8 4 1 9 5 9 0 5 1 9 7 9 9 7 9 6 7 9 9 9 5 4 9 1 3 7 7 0 9 9 8 4 7 9
8 8 9 7 5 2 5 9 5 8 8 9 9 4 9 8 5 9 7 7 8 1 8 8 9 4 2 5 5 9 8 9 1 7 3 8 4 7 7 4
4 8 1 9 6 4 7 9 0 6 5 8 7 8 7 8 2 7 9 8 8 9 4 7 4 8 0 0 1 1 5 9 8 9 5 8 9 9 8 9
8 9 9 0 9 6 0 9 9 6 4 9 9 9 9 7 4 9 2 9 8 3 9 8 7 7 6 9 5 0 9 5 8 7 9 9 6 9 9 9
7 5 9 5 3 9 9 9 9 3 9 3 7 6 8 7 5 9 8 9 9 6 9 9 8 7 9 9 8 9 1 8 9 9 8 9 9 6 9 9
</pre>
