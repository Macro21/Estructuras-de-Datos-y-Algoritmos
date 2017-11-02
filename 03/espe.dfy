method problema3 ( a : array <int > , p : int) returns ( b : bool )
requires a != null
requires 0 <= p < a . Length
ensures b == forall u , w :: 0 <= u <= p < w < a . Length ==> a[u] < a[w]