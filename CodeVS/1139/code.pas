var
	n,m,k,i,j,ans,dd,tt:longint;
	d,x,time,p,arr,sum:array[0..1000]of longint;
	a,b,t:array[1..10000]of longint;
	
	function max(a,b:longint):longint;
	begin
		if a>b then exit(a) else exit(b);
	end;
	
	function min(a,b:longint):longint;
	begin
		if a<b then exit(a) else exit(b);
	end;

begin
	readln(n,m,k);
	for i:=1 to n-1 do read(d[i]);
	for i:=1 to m do begin
		readln(t[i],a[i],b[i]);
		inc(x[b[i]]);
		time[a[i]]:=max(time[a[i]],t[i]);
	end;
	sum[0]:=0;
	for i:=1 to n do sum[i]:=sum[i-1]+x[i];
	while true do begin
		for i:=2 to n do arr[i]:=max(arr[i-1],time[i-1])+d[i-1];
		p[n]:=n;
		for i:=n-1 downto 1 do if arr[i+1]>time[i+1] then p[i]:=p[i+1] else p[i]:=i+1;
		dd:=1;
		while (d[dd]=0)and(dd<n) do inc(dd);
		if (dd=n)or(k=0) then break;
		for i:=1 to n-1 do if (d[i]>0)and(sum[p[i]]-sum[i]>sum[p[dd]]-sum[dd]) then dd:=i;
		tt:=sum[p[dd]]-sum[dd];
		tt:=min(tt,k);
		tt:=min(tt,d[dd]);
		for i:=dd+1 to p[dd]-1 do tt:=min(tt,arr[i]-time[i]);
		k:=k-tt;
		d[dd]:=d[dd]-tt;
	end;
	for i:=1 to m do ans:=ans+arr[b[i]]-t[i];
	writeln(ans);
end.
