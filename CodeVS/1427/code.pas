var
	n,i,j:longint;
	f,a:array[1..1000]of longint;
begin
	readln(n);
	for i:=1 to n do read(a[i]);
	f[1]:=0;
	f[2]:=0;
	for i:=3 to n-1 do begin
		for j:=1 to i-1 do if f[j]+
	end;
end.