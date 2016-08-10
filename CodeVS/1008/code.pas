var
  n,k,i,j,ans:longint;
  a:array[1..20]of longint;

  function check(a:longint):boolean;
  var
    i:longint;
  begin
    for i:=2 to trunc(sqrt(a)) do if a mod i=0 then exit(false);
	check:=true;
  end;

  procedure go(l,h:longint;x:byte);
  var
    i:longint;
  begin
    if x=k then begin
      if check(h) then inc(ans);
	  exit;
	end;
	for i:=l+1 to n-k+x+1 do go(i,h+a[i],x+1);
  end;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  ans:=0;
  go(0,0,0);
  writeln(ans);
end.
