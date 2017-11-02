// El alumno debe rellenar los ...


// Comprobar que un elemento del vector coincide con 
// la posicion que ocupa en el vector

method coincide (v : array<int>) returns (b : bool)
requires v != null
ensures b == (forall i :: 0<=i<v.Length ==> v[i] != i)

method TestCoincide ()
{ 
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 4; v[2] := 1;
	v[3] := 5; v[4] := 7; v[5] := 0;
	var n := coincide(v);
	assert n;
}

// Comprobar que un vector es creciente y que la diferencia
// entre dos valores consecutivos no es mayor que una cantidad

predicate creciente (s : seq<int>) 
ensures creciente(s) == (forall i :: 0<=i<|s|-1 ==> s[i]<s[i+1]) //Estrictamente creciente

//-x<=(a-b)<=x
predicate diferenciaAcotada (s: seq<int>, x : int) 
ensures diferenciaAcotada(s,x) == (forall i :: 0<=i<|s|-1 ==> -x<=(s[i] - s[i+1]) <=x)

method diferencia(v : array<int>, x : int) returns (b : bool)
	requires v != null;
	ensures b== (creciente(v[..]) && diferenciaAcotada(v[..],x))

method TestDiferencia ()
{
	assert creciente([3,5,7]); // para comprobar el predicado creciente
	assert diferenciaAcotada([3,5,6],4);  // para comprobar el predicado diferenciaAcotada
	var v : array<int> := new int[3];
	v[0] := 1; v[1] := 5; v[2] := 6;
	var n := diferencia(v,4);
	assert n;  // Para comprobar el metodo
}


//falla porque no se modificar el count

//Todos los valores de una secuencia estan repetidos una vez y solo una.
function Count(s:seq<int>, x : int):int
	requires exists k :: 0<=k<|s| ==> s[k] ==x
	ensures s == [] ==> Count(s,x) == 0
	ensures s != [] && Count(s,x) == 1 ==> Count(s,x) == 1 + Count(s[1..],x)
	ensures s != [] && Count(s,x) != 2 ==> Count(s,x) == 1 + Count(s[1..],x)
	{
	if |s| == 0 then 0
	else if Count(s,s[0]) == 1 then 1 + Count(s[1..], s[0]) 
	else Count(s[1..],x)
}

/*	
function Count(s:seq<int>, x : int):int
	//requires forall k :: 0 <= k <|s| ==> p.requires(s[k])
	ensures s == [] ==> Count(s,x) == 0
	ensures s != [] && Count(s[0])==2 ==> Count(s,s[1]) == 1 + Count(s[1..], s[1])
	ensures s != [] && Count(s[0]) != 2 ==> Count(s,x) == 0
	{
		if s == [] then 0
		else if p(s[0]) then 1 + Count(s[1..], p)
		else Count(s[1..], p)
	}
	*/

method parejas(v : array<int>) returns (b : bool)
requires v != null && v.Length % 2 == 0; // nr total de elementos tiene que ser par
ensures b == (forall k:: 0<=k<v.Length ==> Count(v[..],v[k]) == 2)

method TestParejas ()
{
	var v : array<int> := new int[6];
	v[0] := 1; v[1] := 5; v[2] := 6;
	v[3] := 1; v[4] := 5; v[5] := 6;
	var n := parejas(v);
	assert n;
}


