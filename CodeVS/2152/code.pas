const
	d:array[1..4,1..2]of longint=((0,1),(0,-1),(1,0),(-1,0));
var
	r,c,i,j,max:longint;
	a:array[0..101,0..101]of longint;
	f:array[1..100,1..100]of longint;
	
	function get(x,y:longint):longint;
	var
		i:longint;
	begin
		if f[x,y]>0 then exit(f[x,y]);
                f[x,y]:=1;
		for i:=1 to 4 do if a[x,y]>a[x+d[i,1],y+d[i,2]] then if get(x+d[i,1],y+d[i,2])+1>f[x,y] then f[x,y]:=get(x+d[i,1],y+d[i,2])+1;
		exit(f[x,y]);
	end;
begin
	readln(r,c);
	fillchar(a,sizeof(a),$7f);
	for i:=1 to r do for j:=1 to c do read(a[i,j]);
	for i:=1 to r do for j:=1 to c do get(i,j);
	for i:=1 to r do for j:=1 to c do if f[i,j]>max then max:=f[i,j];
	writeln(max);
end.
