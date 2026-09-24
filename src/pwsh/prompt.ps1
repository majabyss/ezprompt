Function main {
    $anthropic = Read-Host "Are you using Claude as your agent, y/n?"

    if ($anthropic -ne 'y' -and $anthropic -ne 'n') {
        Write-Host "Error: Unknown input!"
        exit 1
    }

    $role = Read-Host "What is this agent's role? (e.g. An experienced software engineer)"
    $objective = Read-Host "What is this agent's objective? (e.g. Build an app that tracks my daily routine) <- Keep this to one sentence."
    $context = Read-Host "What context should the agent know? (e.g. I am a very busy person and can't keep track of my day to day life)."
    $task = Read-Host "What is the task for this agent? (e.g. Step 1... Step 2... etc.) <- This is for more detailed instructions than the end objective."
    $constraints = Read-Host "What constraints should this agent follow? (e.g. Never use old C++ versions)."
    $out_fmt = Read-Host "What should the output format be? (e.g. A file, some text, etc)."
    $examples = Read-Host "(Optional) Are there any specific examples the agent should know? (e.g. X fails to load on Y system)."
    $reasoning = Read-Host "(Optional) How should the agent think/reason? (e.g. Think step by step)."

    if ($anthropic -eq 'y') {
        $content = @"
<role>
$role
</role>
<context>
$context
</context>
<examples>
$examples
</examples>
<constraints>
$constraints
</constraints>
<objective>
$objective
</objective>
<task>
$task
</task>
<output_format>
$out_fmt
</output_format>
<reasoning>
$reasoning
</reasoning>
"@
        $content | Out-File -FilePath "prompt.xml" -Encoding utf8
        exit 0
    } elseif ($anthropic -eq 'n') {
        $content = @"
## ROLE
$role
## OBJECTIVE
$objective
## CONTEXT
$context
## TASK
$task
## CONSTRAINTS
$constraints
## OUTPUT
$out_fmt
## EXAMPLES
$examples
## REASONING
$reasoning
"@
        $content | Out-File -FilePath "prompt.md" -Encoding utf8
        exit 0
    }
}

main
