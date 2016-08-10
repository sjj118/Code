var
	n,i,j,k,q,x,y:longint;
	a:array[1..100,1..100]of longint;
begin
	readln(n);
	for i:=1 to n do for j:=1 to n do read(a[i,j]);
	for k:=1 to n do
		for i:=1 to n do
			for j:=1 to n do
				if a[i,k]+a[k,j]<a[i,j] then a[i,j]:=a[i,k]+a[k,j];
	readln(q);
	for i:=1 to q do begin
		readln(x,y);
		writeln(a[x,y]);
	end;
end.