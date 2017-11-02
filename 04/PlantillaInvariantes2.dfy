// Vector de acumulados suponiendo que el vector no es vac’o
// El vector v es de salida. Se asegura en el ensures que estar‡ definido
// se le reserva memoria en el c—digo

function SumP1Elem(s:seq<int>, p:(int)->bool):int
	reads p.reads
	requires forall k :: 0 <= k <|s| ==> p.requires(s[k])
	ensures s==[] ==> SumP1Elem(s,p)==0
	ensures s!=[] && p(s[0]) ==>
	SumP1Elem(s,p)==s[0]+SumP1Elem(s[1..], p)
	ensures s!=[] && !p(s[0])==>
	SumP1Elem(s,p)==SumP1Elem(s[1..], p)
	{
		if s == [] then 0
		else if p(s[0]) then s[0] +SumP1Elem(s[1..], p)
		else SumP1Elem(s[1..], p)
	}	
predicate positivos (n : int)
{ true}


method problema1 (a: array<int>) returns (v : array<int>)
requires a != null && a.Length > 0
ensures v != null && v.Length > 0 && a.Length == v.Length
ensures forall i :: 1<=i<a.Length ==> v[v.Length -1 - i] == SumP1Elem(a[(v.Length -1 - i)..],positivos);
{
	v := new int[a.Length];
	var tamDatos := a.Length;
	var i := 1;
	
	assert tamDatos -1 >=0;
	v[tamDatos -1] := a[tamDatos-1];
	assert i == 1 && 1<=i+1<tamDatos && forall k:: 1<= k < tamDatos ==> v[tamDatos - k] + a[tamDatos - 1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos);
	while (i < tamDatos)
		invariant 1<=i<tamDatos
		invariant forall k:: 1<= k < tamDatos ==> v[tamDatos -1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos);
		decreases tamDatos - i
	{
		assert 1<=i+1<tamDatos && forall k:: 1<=k<i ==> v[tamDatos - k] + a[tamDatos - 1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos) ==>
		1<=i+1<tamDatos && forall k:: 1<=k<i+1 ==> v[tamDatos - k] + a[tamDatos - 1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos);
		v[tamDatos - 1 - i] := v[tamDatos - i] + a[tamDatos - 1 - i];
		assert 1<= i + 1 < tamDatos && forall k:: 1<= k < i+1 ==> v[tamDatos - k] + a[tamDatos - 1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos);
		i := i+1;
		assert 1<= i < tamDatos && forall k:: 1<= k <i ==> v[tamDatos - k] + a[tamDatos - 1 - k] == SumP1Elem(a[(tamDatos -1 - k)..],positivos);
	}
}

/*

// Vector acumulado suponiendo que el vector puede ser vacio

method problema2 (a: array<int>) returns (v : array<int>)
requires a != null 
ensures v != null && a.Length == v.Length
ensures ...
{
	v := new int[a.Length];
	...
}


// n-esimo termino de la sucesion de Fibonacci
function Fib (n : int) : int
{
	if (n < 2) then n
	else Fib(n-2) + Fib(n-1)
}

method Fibonacci (n : int) returns (f : int)
requires n >= 0
ensures ...
{
	...
}
*/