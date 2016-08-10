var
	a,b:array[1..100,1..100]of longint;
	f,v,i,j,k,max:longint;
begin
	readln(f,v);
	for i:=1 to f do
		for j:=1 to v do read(a[i,j]);
	for i:=1 to v-f+1 do b[1,i]:=a[1,i];
	for i:=2 to f do
		for j:=i to v-f+i do
			for k:=i-1 to j-1 do
				if b[i-1,k]+a[i,j]>b[i,j] then begin
					b[i,j]:=b[i-1,k]+a[i,j];
				end;
	max:=0;
	for i:=f to v do
		if b[f,i]>max then max:=b[f,i];
	writeln(max);
end.