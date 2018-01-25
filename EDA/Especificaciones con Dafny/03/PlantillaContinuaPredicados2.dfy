// Nombre del alumno: Andrei Ionut Vaduva, E60

// Rellenar los ...


predicate divisible(n1 : int, n2 : int)
requires n1 >= 0 && n2 > 0 
ensures divisible(n1,n2) == (n1 % n2 == 0)


method TestDivisible()
{
	assert divisible(5,1);
	assert divisible(25,5);
	assert divisible(1000,1000);
	//assert divisible(10,20); // Este assert debe fallar
	//assert divisible(-5,2); // Este assert debe fallar
	//assert divisible(0,5);  // Este assert debe fallar
	//assert divisible(2,0); // Este assert debe fallar
	//assert divisible(1001,100);  // Este assert debe fallar
}


predicate VectorDivisible (s : seq<int>, n : int)
requires n > 0
requires forall i:: 0<=i<|s| ==> s[i]>=0
ensures VectorDivisible(s,n) == (forall k :: 0<=k<|s| ==> divisible(s[k],n))

method TestDivisibles() 
{
	assert VectorDivisible([99],3);
	assert VectorDivisible([5,100,10,25],5);
	var s : seq<int>;
	s := [];
	assert VectorDivisible(s,3);
	//assert VectorDivisible([3,5,2,4,3,8,4,6,1,10],-2); // Este assert debe fallar
	assert VectorDivisible([0,0,0],4);
	//assert VectorDivisible([3,4],0);  // Este assert debe fallar
	//assert VectorDivisible([-4,3],2);  // Este assert debe fallar
	//assert VectorDivisible([4,3],2);  // Este assert debe fallar
}

predicate CrecienteM1(s: seq<int>)
ensures CrecienteM1(s) == (forall i:: 0<=i<(|s|-1) ==> s[i]<s[i+1])

predicate Capicua(s: seq<int>)
ensures Capicua(s) == forall i ::0<=i<|s| ==> s[i] == s[|s|- i - 1 ]

predicate Decreciente(s:seq<int>)
ensures Decreciente(s) == forall i :: 0<=i<|s|-1 ==> s[i] > s[i+1]

predicate Montana (s : seq<int>) //caso s par
ensures Montana(s) == (|s| == 1) // si tengo un solo valor
ensures Montana(s) == (|s| % 2 == 0 && Capicua(s) && CrecienteM1(s[..(|s|/2)]) && Decreciente(s[(|s|/2)..]))//si la sec tiene un nr par de elementos
ensures Montana(s) == (|s| % 2 != 0 && Capicua(s) && CrecienteM1(s[..((|s|/2)-1)]) && Decreciente(s[((|s|/2)+1)..])) // si la sec tiene un nr impar de elems



method TestMontana() 
{
	assert Montana([2]);
	assert Montana([2,2]);
	assert Montana([-2,3,4,3,-2]);
	assert Montana([-2,3,3,-2]);
	assert Montana([5,6]); // Este assert debe fallar
	var s : seq<int>;
	s := [];
	assert Montana(s);
	assert Montana([0,0,0,0]); // Este assert debe fallar
	assert Montana([0,0,0]); // Este assert debe fallar
	assert Montana([3,-4,-4,3]);  // Este assert debe fallar
}
