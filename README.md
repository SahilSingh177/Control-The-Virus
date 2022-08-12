# Control-The-Virus
### Problem Statement :
<p align="left">
    Designing an efficient method to limit the spread of the virus utilizing limited
    available resources.
</p>
    
### Explanation of this project :
<p align="left">
<img src="https://scopeblog.stanford.edu/wp-content/uploads/2020/03/Coronvirus2-CDC-.jpg" alt="Node JS" width="390" height="290" style="vertical-align:top; margin:4px" align="right">
    A virus has gripped a village and is spreading at an alarming rate. With each
    passing night, the virus multiplies in all directions. To prevent the spread of
    this virus, we need to quarantine as many houses affected as possible.
    Because of limited resources, we can quarantine only a single block of houses
    in a day.
</p>

### Motivation :
<p align="left">
    Current global crisis has taken a toll on all our lives. Following the pandemic,
    reducing the effect of the virus was a matter of utmost importance. So, we
    tried to come up with an idea of quarantining the affected houses thus
    minimizing the spread of the virus if we had a chance.
</p>

### Proposed Solution :
<p align="left">
    The aim of our project is to quarantine those clusters of infected houses which
    will have a massive impact on the outspread of the virus. Owing to the limited
    resources, we will first quarantine that part of the village where the maximum
    number of houses will be affected overnight. By the next day, the virus must
    have spread in the other parts of the village. Then, we analyze the condition.
</p>

### Approach to solve this problem:  
<p align="left">
      Here we assume a village is an mXn grid.
      <br>
        Constraints
      <br>
      There will never be a tie.
      The cluster of affected houses will always form a rectangle.
      In this, we utilize 2 functions:- <br><br>  
      1.) The first function identifies which cluster of houses should be
      quarantined first. <br>
      2.) Since in one day we can quarantine only one cluster, the second
      function provides us with where the virus has spread in one night. <br>
      So, we take a 2-D array where 0 represents unaffected houses and 1 represent houses affected by the virus . As mentioned above, we call two different
      functions which consist of various loops and conditional statements. <br>
      For example: -
      Based on the above diagram, we quarantine the 5 affected houses on the right. Since the left side couldn’t be quarantined the virus has spread overnight. So, now on the next day we
      quarantine this side. To represent the quarantined
      houses we mark them as -1. Thus, we have stopped
      the virus outbreak.
</p> 
Proposed Solution:
<p align="left">
    We illustrate an example below, displaying the results of our code
    We take a 6X6 grid to show the village affected by the virus.
    In this example, there are 2 clusters of houses that are already affected by the virus.
 </p>
<br>  
<p align="center">
1 1 0 0 0 0 <br>  
1 1 0 0 0 0 <br>  
0 0 0 0 0 0 <br>  
0 0 0 1 1 0 <br>  
0 0 0 1 1 0 <br>  
0 0 0 0 0 0 <br>  
</p>
<p align="left">
Function Wall
As we can see the top-left cluster will affect 5 houses whereas the other
cluster affects 10 houses. Utilizing the first function, we identify the cluster of
houses to be quarantined and change their value to 2. </p><br>
<p align="center">
1 1 0 0 0 0 <br>  
1 1 0 0 0 0 <br>  
0 0 0 0 0 0 <br>  
0 0 0 2 2 0 <br>  
0 0 0 2 2 0 <br>  
0 0 0 0 0 0 <br>  </p>
Function Overnight
Now, the second function is called which increases the affected houses
overnight because of the lack of resources. We show this by spreading the
virus to the neighbouring houses. <br><br>
Final Output <br>
As we can clearly see there is only one cluster of houses left, the functions
quarantine the last cluster and terminate the loop. <br>
<p align="center">
1  1  1  0  0  0 <br>
1  1  1  0  0  0 <br>
1  1  1  0  0  0 <br>
0  0  0 -1 -1  0 <br>
0  0  0 -1 -1  0 <br>
0  0  0  0  0  0 <br>
</p>

<p align="center">
2  2  2  0  0  0 <br>
2  2  2  0  0  0 <br>
2  2  2  0  0  0 <br>
0  0  0 -1 -1  0 <br>
0  0  0 -1 -1  0 <br>
0  0  0  0  0  0 <br> </p>
<p align="right">
 

Hence, the affected houses were quarantined and the village was saved. <br>
Total number of houses quarantined: 13 <br>
Total number of houses saved: 23 <br>
Number of nights to stop the virus: 2 <br>
 </p>
<p align="center">
-1 -1 -1 0 0 0 <br>
-1 -1 -1 0 0 0 <br>
-1 -1 -1 0 0 0 <br>
0 0 0 -1 -1 0 <br>
0 0 0 -1 -1 0<br>
0 0 0 0 0 0 <br>
</p>
In order to save a village from being affected by a virus, given the limited
number of resources available, it is important to first quarantine those cluster
of houses which could lead to a massive outbreak of the virus in the village. To
achieve this task, we design an approach that limits the spread of the virus
overnight and tries to save the village with the resources available. Our
approach can be modified using preexisting approaches like back tracking to
minimize this effort. <br><br>
<p align="center">
 <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ1pt7BhQNzDx7JnF4emcdpz2dqLrrk5nW3NPnzYezt&s" alt="Node JS" width="320" height="290" style="vertical-align:top; margin:24px; ">
</p>
