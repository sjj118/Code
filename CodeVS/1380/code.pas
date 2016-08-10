var
	n,i,j,l,k,ans:longint;
	son:array[1..6000,0..6000]of longint;
	r:array[1..6000]of longint;
	f:array[1..6000,1..2]of longint;
	p:array[1..6000]of boolean;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
	
	function get(k,t:longint):longint;
	var
		i:longint;
	begin
		if f[k,t]<>0 then exit(f[k,t]);
		if t=2 then begin
			f[k,t]:=r[k];
			for i:=1 to son[k,0] do f[k,t]:=f[k,t]+get(son[k,i],1);
		end else begin
			for i:=1 to son[k,0] do f[k,t]:=f[k,t]+max(get(son[k,i],1),get(son[k,i],2));
		end;
		exit(f[k,t]);
	end;
begin
	readln(n);
        for i:=1 to n do readln(r[i]);
        readln(l,k);
	while l>0 do begin
		inc(son[k,0]);
		son[k,son[k,0]]:=l;
		p[l]:=true;
                readln(l,k);
	end;
	for i:=1 to n do if not p[i] then begin
		ans:=max(get(i,1),get(i,2));
		break;
	end;
	writeln(ans);
end.
