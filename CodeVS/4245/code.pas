const
	mo=10007;
var
	n:int64;
	
	function mi(x,n,m:int64):int64;
	var
		t:int64;
	begin
		if n=0 then exit(1);
		if n=1 then exit(x mod m);
		t:=mi(x,n div 2,m);
		exit(t*t mod m*mi(x,n mod 2,m)mod m);
	end;
	
	function sqrsum(n:int64):int64;
	begin
		exit(n mod mo*(n+1)mod mo*(2*n+1)mod mo*mi(6,mo-2,mo)mod mo);
	end;
begin
	readln(n);
	writeln(sqrsum(n)*2 mod mo);
end.
