var
  n,k,i,j,l,m:longint;
  f:array[0..6,0..200]of longint;
begin
  readln(n,k);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do f[1,i]:=1;
  for i:=2 to k do begin
    for j:=i to n do begin
	  f[i,j]:=f[i-1,j-1]+f[i,j-i];
	end;
  end;
  writeln(f[k,n]);
end.