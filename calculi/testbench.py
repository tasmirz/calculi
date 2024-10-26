import agents.library as library
A= library.to_np(
[[7 ,4,-2], 
 [4,-3,-8], 
 [5,9,3]]
 )
print(library.is_digonally_domainant(A))
library.make_diagonally_dominat(A)