{
ID: sjj22451
LANG: PASCAL
PROB: transform
}
var
  n,i,j:longint;
  a,b,c:array[1..10,1..10]of char;
  same:boolean;

  function b1:boolean;
  var
    i,j:longint;
  begin
    for i:=1 to n do begin
	  for j:=1 to n do begin
	    if a[i,j]<>b[j,n-i+1] then exit(false);
	  end;
	end;
	exit(true);
  end;

  function b2:boolean;
  var
    i,j:longint;
  begin
    for i:=1 to n do begin
	  for j:=1 to n do begin
	    if a[i,j]<>b[n-i+1,n-j+1] then exit(false);
	  end;
	end;
	exit(true);
  end;

  function b3:boolean;
  var
    i,j:longint;
  begin
    for i:=1 to n do begin
	  for j:=1 to n do begin
	    if a[i,j]<>b[n-j+1,i] then exit(false);
	  end;
	end;
	exit(true);
  end;

  function b4:boolean;
  var
    i,j:longint;
  begin
    c:=b;
    for i:=1 to n do begin
	  for j:=1 to n do begin
	    b[i,n-j+1]:=c[i,j];
	  end;
	end;
	for i:=1 to n do begin
	  for j:=1 to n do begin
	    if a[i,j]<>b[i,j] then exit(false);
	  end;
	end;
	exit(true);
  end;

  function b5:boolean;
  var
    i,j:longint;
  begin
    exit(b1 or b2 or b3);
  end;

  function b6:boolean;
  var
    i,j:longint;
  begin
    for i:=1 to n do for j:=1 to n do if a[i,j]<>b[i,j] then exit(false);
    exit(true);
  end;
begin
  assign(input,'transform.in');reset(input);
  assign(output,'transform.out');rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do readln(b[i]);
  same:=b6;
  if b1 then writeln(1)
  else if b2 then writeln(2)
  else if b3 then writeln(3)
  else if b4 then writeln(4)
  else if b5 then writeln(5)
  else if same then writeln(6)
  else writeln(7);
  close(input);close(output);
end.
