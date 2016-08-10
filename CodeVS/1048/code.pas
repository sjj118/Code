var
  f:array[1..100,1..100]of longint;
  w,s:array[0..100]of longint;
  n,i,j,k:longint;
begin
  readln(n);
  for i:=1 to n do read(w[i]);
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+w[i];
  for i:=1 to n do for j:=1 to n do f[i,j]:=maxlongint;
  for i:=1 to n do f[i,i]:=0;
  for i:=2 to n do begin
	for j:=i-1 downto 1 do begin
	  for k:=j to i-1 do begin
	    if(f[j,k]+f[k+1,i]+s[i]-s[j-1]<f[j,i])then f[j,i]:=f[j,k]+f[k+1,i]+s[i]-s[j-1];
	  end;
	end;
  end;
  writeln(f[1,n]);
end.
