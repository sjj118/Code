var
  n,m,i,j,k,x1,y1,x2,y2:longint;
  f:array[-5..59,-19..59]of int64;
begin
  readln(n,m);
  readln(x1,y1,x2,y2);
  fillchar(f,sizeof(f),0);
  f[x1,y1]:=1;
  for i:=x1+1 to x2 do begin
    for j:=1 to m do begin
      f[i,j]:=f[i-1,j-2]+f[i-1,j+2]+f[i-2,j-1]+f[i-2,j+1];
    end;
  end;
  writeln(f[x2,y2]);
end.