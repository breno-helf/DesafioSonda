# DesafioSonda
This is a challenge proposed by Cappta. You can see it [here](https://gist.github.com/rmterra/31f2b4f589250839550f685d8873d935)

- To compile the program just run "make sonda".

- To compile the binary for tests run "make test"	

The assumptions made were:

    - When a "sonda" finish its trajectory it stops at the ending position, occupying that position.

    - All the occupied positions are invalid (i.e ignored)

    - All the positions outside the grid are invalid (i.e ignored)


The additional features added were min_dist between a robot and a position and a function to print the grid.
      
PS: "in" file is the default input
