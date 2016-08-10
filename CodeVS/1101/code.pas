var
	n,i:longint;
	x,y:array[1..50,1..50]of longint;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
	
	function min(a,b:longint):longint;
	begin
		if a<b then exit(a) else exit(b);
	end;
	
begin
	readln(n,k);
	for i:=1 to n do readln(x[i],y[i]);
	
end.