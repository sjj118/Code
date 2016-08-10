var
  n,m,i,j,k,l:longint;
  a:array[0..350]of longint;
  f:array[-1..40,-1..40,-1..40,-1..40]of longint;
  w:array[1..4]of longint;
  
  function max(a,b,c,d:longint):longint;
  begin
	max:=0;
	if a>max then max:=a;
	if b>max then max:=b;
	if c>max then max:=c;
	if d>max then max:=d;
  end;
begin
  readln(n,m);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do begin
    read(j);
	inc(w[j]);
  end;
  for i:=0 to w[1] do
	for j:=0 to w[2] do
	  for k:=0 to w[3] do
		for l:=0 to w[4] do begin
		  f[i,j,k,l]:=max(f[i-1,j,k,l],f[i,j-1,k,l],f[i,j,k-1,l],f[i,j,k,l-1])+a[i+j*2+k*3+l*4+1];
		end;
  writeln(f[w[1],w[2],w[3],w[4]]);
end.
