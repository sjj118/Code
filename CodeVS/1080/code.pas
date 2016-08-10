var
	n,m,i,j,x,a,op:longint;
	tree,left,right:array[1..300000]of longint;
	
	procedure init;
		procedure setarr(t,l,r:longint);
		var
			mid:longint;
		begin
			left[t]:=l;
			right[t]:=r;
			if l=r then exit;
			mid:=(l+r) div 2;
			setarr(t*2,l,mid);
			setarr(t*2+1,mid+1,r);
		end;
	begin
		setarr(1,1,n);
	end;
	

	procedure add(x,a:longint);
		procedure tadd(t,x,a:longint);
		begin
			tree[t]:=tree[t]+a;
			if left[t]=right[t] then exit;
			if x<=right[2*t] then tadd(2*t,x,a) else tadd(2*t+1,x,a);
		end;
	begin
		tadd(1,x,a);
	end;
	
	function sum(l,r:longint):longint;
		function tsum(t,l,r:longint):longint;
		begin
			if (l=left[t])and(r=right[t]) then exit(tree[t]);
			tsum:=0;
			if l<=right[2*t] then begin
				if r<=right[2*t] then tsum:=tsum+tsum(2*t,l,r) else tsum:=tsum+tsum(2*t,l,right[2*t])+tsum(2*t+1,left[2*t+1],r);
			end else begin
				tsum:=tsum+tsum(2*t+1,l,r);
			end;
		end;
	begin
		exit(tsum(1,l,r));
	end;
begin
	readln(n);
	init;
	for i:=1 to n do begin
		readln(j);
		add(i,j);
	end;
	readln(m);
	for i:=1 to m do begin
		readln(op,x,a);
		if op=1 then begin
			add(x,a);
		end else begin
			writeln(sum(x,a));
		end;
	end;
end.
