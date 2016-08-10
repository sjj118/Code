var
  n,m,i,j,max,maxx,maxy:longint;
  a:array[0..21,0..21]of longint;
  b:array[1..20,1..20]of longint;
begin
  max:=-maxlongint;
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to n do
    for j:=1 to m do begin
      b[i,j]:=a[i-1,j]+a[i+1,j]+a[i,j+1]+a[i,j-1];
      if b[i,j]>max then begin
        max:=b[i,j];
        maxx:=i;
        maxy:=j;
      end;
    end;
  writeln(maxx,' ',maxy,' ',max);
end.