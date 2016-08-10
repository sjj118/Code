var
  n,m,i,j,l:longint;
  s:array[1..100]of string;
  a:array[1..100]of longint;

  procedure qsort(l,r:longint);
  var
    x,i,j,t:longint;
	y:string;
  begin
    x:=a[(l+r)div 2];
	i:=l;
	j:=r;
	repeat
	  while a[i]<x do inc(i);
	  while a[j]>x do dec(j);
	  if (i<=j) then begin
            if a[i]<>a[j] then begin
	    t:=a[i];
		a[i]:=a[j];
		a[j]:=t;
		y:=s[i];
		s[i]:=s[j];
		s[j]:=y;
            end;
		inc(i);
		dec(j);
	  end;
	until i>j;
	if l<j then qsort(l,j);
	if r>i then qsort(i,r);
  end;
begin
  readln(n,m);
  for i:=1 to m do readln(s[i]);
  for i:=1 to m do begin
    for j:=1 to n-1 do begin
	  for l:=j+1 to n do begin
	    if ord(s[i][j])>ord(s[i][l]) then inc(a[i]);
	  end;
	end;
  end;
  qsort(1,m);
  for i:=1 to m do writeln(s[i]);
end.
