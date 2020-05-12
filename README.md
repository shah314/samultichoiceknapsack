<H1>Simulated Annealing Algorithm for the Multiple Choice Multidimensional Knapsack Problem</H1>

<i><h3>Shalin Shah</h3></i>
<a href="https://zenodo.org/badge/latestdoi/134318963"><img src="https://zenodo.org/badge/134318963.svg" alt="DOI"></a>

<P>Implementation of simulated annealing algorithm for the multiple choice  multidimensional knapsack problem. The multiple choice knapsack problem has <I>n</I> groups of items and <I>m</I> constraints. The objective is to choose one item from each group such that the total value (profit) is maximized while all of the m constraints are satisfied. </P>
<p>
The implementation is quite fast, and the code finds optimum or very close to optimum solutions in a very short duration.
</p>
<br>
<b>Usage:</b>
<pre>
- Compile the code using g++
- e.g. g++ saMultiChoiceKnapsack.cpp
- Run ./a.out filename iterations
- e.g. ./a.out instances/I01 100000
</pre>
<br>
<P>Instances are available at the following FTP site and also in the instances folder:<br>
ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/<br>
ftp://cermsem.univ-paris1.fr/pub/CERMSEM/hifi/MMKP/MMKP.html</br>
</P>
<br>
<b>Cite this code:</b>
<pre>
@misc{shah2014mcknapsack,
  title={Simulated Annealing Algorithm for the Multiple Choice Multidimensional Knapsack Problem},
  author={Shah, Shalin},
  year={2020},
  DOI={10.5281/zenodo.3820939}
}
</pre>
<b>Cited By:</b>
<ul>
  <li>Heikal, A. F., et al. "A New Genetic Algorithm for Multiple-Choice Multidimensional Knapsack Problem." The International Conference on Electrical Engineering. Vol. 7. No. 7th International Conference on Electrical Engineering ICEENG 2010. Military Technical College, 2010.</li>
</ul><br>

<b>Results:</b><br>
Results on some instances (from the instances directory and at the above mentioned FTP site). The algorithm is quite fast and takes only a few seconds for 100000 iterations). The code is able to find optimum solutions for almost all instances (or at least a close to optimum solution)<br>
<table>
	<tr><td>Instance</td><td>Best Known Solution</td><td>This Algorithm's Solution</td></tr>
	<tr><td>I01</td><td>173</td><td><b>173</b></td></tr>
  <tr><td>I02</td><td>364</td><td><b>361</b></td></tr>
  <tr><td>I03</td><td>1602</td><td><b>1595</b></td></tr>
  <tr><td>I04</td><td>3597</td><td><b>3542</b></td></tr>
  <tr><td>I05</td><td>3905</td><td><b>3900</b></td></tr>
  <tr><td>I06</td><td>4799</td><td><b>4792</b></td></tr>
  <tr><td>I07</td><td>23912</td><td><b>24225</b></td></tr>
  <tr><td>I08</td><td>35979</td><td><b>36283</b></td></tr>
  <tr><td>I09</td><td>47901</td><td><b>48308</b></td></tr>
  <tr><td>I10</td><td>59811</td><td><b>60419</b></td></tr>
  <tr><td>I11</td><td>71760</td><td><b>72494</b></td></tr>
  <tr><td>I12</td><td>84141</td><td><b>84615</b></td></tr>
  <tr><td>I13</td><td>96003</td><td><b>96791</b></td></tr>
</table><br>
