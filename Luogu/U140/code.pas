var
  n,m,k,q,bb:longint;
  s,ans,l1,l2:int64;

  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;

  function min(a,b:longint):longint;
  begin
    if a>b then min:=b else min:=a;
  end;

begin
  readln(n,m,k);
  l1:=0;
  bb:=min(max(n,m),trunc(sqrt(k)));
  while l1<bb do begin
    inc(l1);
	if (l1<=n) then begin
	  l2:=min(k div l1,m);
	  q:=k-l1*l2;
	  s:=l1*(l1-1)div 2*l2*(l2-1)div 2;
	  if q>1 then
	  if m>l2 then s:=s+l2*(q-1)
	  else s:=s+l1*(q-1)
	end;
	if s>ans then ans:=s;
	if (l1<=m) then begin
	  l2:=min(k div l1,n);
	  q:=k-l1*l2;
	  s:=l1*(l1-1)div 2*l2*(l2-1)div 2;
	  if q>1 then
	  if m>l2 then s:=s+l2*(q-1)
	  else s:=s+l1*(q-1);
	end;
	if s>ans then ans:=s;
  end;
  writeln(ans);
end.
