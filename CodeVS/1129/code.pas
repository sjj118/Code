var
  a:array[1..500,1..500]of longint;
  i,j,n,max,max2,mans:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    for j:=1 to n-i do read(a[i,i+j]);
  for i:=1 to n do
    for j:=1 to i-1 do a[i,j]:=a[j,i];
  for i:=1 to n do begin
    max:=-1;
    max2:=-1;
    for j:=1 to n do begin
      if a[i,j]>max then begin
        max2:=max;
        max:=a[i,j];
      end;
      if (a[i,j]>max2) and (a[i,j]<max) then begin
        max2:=a[i,j];
      end;
    end;
    if(max2>mans)then mans:=max2;
  end;
  writeln(1);
  writeln(mans);
end.