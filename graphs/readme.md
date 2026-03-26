what are connected components and why we maintain a visited array?

in hinglish lang

Connected components ek graph ke aise subgraphs hote hain jisme har node doosre node se directly ya indirectly connected hota hai. Matlab, agar hum ek node se start karte hain aur uske saare neighbors ko visit karte hain, toh hum ek connected component ke andar hi rahenge.


Visited array maintain karna isliye zaroori hota hai taaki hum track kar sakein ki humne kaunse nodes ko already visit kiya hai. Isse humein pata chalta hai ki humne kis node ko explore kiya hai aur kis node ko nahi. Agar humne kisi node ko visit kar liya hai, toh uske neighbors ko dobara visit karne ki zaroorat nahi hoti, kyunki woh already connected component ke andar hain. Isse hum time aur resources bachate hain.


graph jarurui nahi hai saare connected hi ho alag bhi ho sakta hai suppose 1,2,3,4 connected hain aur 5,6 connected hain toh humare graph me do connected components honge. Isliye hum visited array maintain karte hain taaki hum alag-alag connected components ko identify kar sakein aur unhe explore kar sakein.