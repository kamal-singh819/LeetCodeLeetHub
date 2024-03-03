<h2><a href="https://leetcode.com/problems/apply-operations-to-make-string-empty/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3039. Apply Operations to Make String Empty</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code>.</p>

<p>Consider performing the following operation until <code>s</code> becomes <strong>empty</strong>:</p>

<ul>
	<li>For <strong>every</strong> alphabet character from <code>'a'</code> to <code>'z'</code>, remove the <strong>first</strong> occurrence of that character in <code>s</code> (if it exists).</li>
</ul>

<p>For example, let initially <code>s = "aabcbbca"</code>. We do the following operations:</p>

<ul>
	<li>Remove the underlined characters <code>s = "<u><strong>a</strong></u>a<strong><u>bc</u></strong>bbca"</code>. The resulting string is <code>s = "abbca"</code>.</li>
	<li>Remove the underlined characters <code>s = "<u><strong>ab</strong></u>b<u><strong>c</strong></u>a"</code>. The resulting string is <code>s = "ba"</code>.</li>
	<li>Remove the underlined characters <code>s = "<u><strong>ba</strong></u>"</code>. The resulting string is <code>s = ""</code>.</li>
</ul>

<p>Return <em>the value of the string </em><code>s</code><em> right <strong>before</strong> applying the <strong>last</strong> operation</em>. In the example above, answer is <code>"ba"</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aabcbbca"
<strong>Output:</strong> "ba"
<strong>Explanation:</strong> Explained in the statement.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> "abcd"
<strong>Explanation:</strong> We do the following operation:
- Remove the underlined characters s = "<u><strong>abcd</strong></u>". The resulting string is s = "".
The string just before the last operation is "abcd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>