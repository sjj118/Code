var
	c:array[1..1000,1..1000]of boolean;
	top,n,m,i,j,k,s,l,p:longint;
	lastest,a:array[1..1000]of longint;
	r:array[1..1000]of longint;
	stack:array[0..1000000]of longint;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
begin
	readln(n,m);
	for i:=1 to m do begin
		read(s);
		for j:=1 to s do read(a[j]);readln;
		for l:=1 to s-1 do begin
			for k:=a[l]+1 to a[l+1]-1 do begin
				for j:=1 to s do if not c[a[j],k] then begin
					c[a[j],k]:=true;
					inc(r[k]);
				end;
			end;
		end;
	end;
	top:=0;
	for i:=1 to n do if r[i]=0 then begin
		inc(top);
		stack[top]:=i;
		lastest[i]:=1;
	end;
	while top>0 do begin
		s:=stack[top];
		dec(top);
		for i:=1 to n do if c[s,i] then begin
			dec(r[i]);
			lastest[i]:=max(lastest[i],lastest[s]+1);
			if r[i]=0 then begin
				inc(top);
				stack[top]:=i;
			end;
		end;
	end;
	s:=0;
	for i:=1 to n do s:=max(s,lastest[i]);
	writeln(s);
end.