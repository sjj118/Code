var
  n,i,j,k:longint;
  c:array[1..50,1..50]of longint;
  ans:int64;
begin
  readln(n);
  for i:=1 to n do c[i,1]:=1;
  for i:=2 to n do begin
    for j:=2 to i do begin
	  for k:=1 to (i-j) div j+1 do begin
	    c[i,j]:=c[i,j]+c[i-k-(j-1)*(k-1),j-1];
	  end;
	end;
  end;
  for i:=1 to n do ans:=ans+c[n,i];
  writeln(ans);
end.
