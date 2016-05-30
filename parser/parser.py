#!py -3

import sys
import os
import re

ignore = frozenset([
	"template.h",
	"lib_assert.h",
	"type_traits.h",
	"utils.h",
])

stack = []
lock = 0

def ifOpen(value):
	global lock
	global stack
	lock += int(not value)
	stack.append(value)

def ifClose():
	global lock
	global stack
	lock -= int(not stack.pop())

def ifElse():
	global lock
	global stack
	lock -= int(not stack[-1])
	stack[-1] = not stack[-1]
	lock += int(not stack[-1])


defines = {}

def defined(key):
	return key in defines

def calcExpression(expr):
	expr = expr.replace('||', 'or').replace('&&', 'and')
	pattern = re.compile('\\bdefined\s*\(([^()]*)\)')
	expr = pattern.sub('defined("\\1")', expr)
	sys.stdout.flush()
	return eval(expr, {'defined':lambda v: defined(v)}, defines)


used = set()
firstLine = True

libPath = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir)

def parse(prevDir, newPath):
	global firstLine
	
	if os.path.isfile(os.path.join(prevDir, newPath)):
		path = os.path.join(prevDir, newPath)
	elif os.path.isfile(os.path.join(libPath, newPath)):
		path = os.path.join(libPath, newPath)
	else:
		raise IOError("lib not found")

	path = os.path.normpath(path)

	filename = os.path.basename(path)
	isIgnored = (filename in ignore) or (filename.endswith('.cpp')) 
	isDuplicate = path in used
	if not isDuplicate:
		used.add(path)

	with open(path) as file:
		needNewLine = False
		for line in file:
			line = line.rstrip('\n')
			trimmedLine = line.lstrip('\t')

			if trimmedLine.startswith('#pragma once'):
				if isDuplicate:
					return
				continue

			if not isIgnored:
				if trimmedLine.startswith('#ifdef'):
					ifOpen(trimmedLine[len('#ifdef'):].strip() in defines)
					continue

				if trimmedLine.startswith('#ifndef'):
					ifOpen(not trimmedLine[len('#ifndef'):].strip() in defines)
					continue

				if trimmedLine.startswith('#if'):
					ifOpen(calcExpression(trimmedLine[len('#if'):]))
					continue

				if trimmedLine.startswith('#endif'):
					ifClose()
					continue

				if trimmedLine.startswith('#else'):
					ifElse()
					continue

				if trimmedLine.startswith('#elif'):
					ifElse()
					ifOpen(calcExpression(trimmedLine[len('#elif'):]))
					continue

				if lock > 0:
					continue

				if trimmedLine.startswith('#define'):
					parts = trimmedLine[len('#define'):].split(maxsplit=1)
					if len(parts) == 1:
						defines[parts[0]] = ""
					else:
						defines[parts[0]] = parts[1]
					continue

				if trimmedLine.startswith('#undef'):
					key = trimmedLine[len('#undef'):].strip()
					if key in defines:
						del defines[key]
					continue

			if trimmedLine.startswith('#include'):
				parts = trimmedLine[len('#include'):].split('"')
				if len(parts) > 1:
					parse(os.path.dirname(path), parts[1])
					needNewLine = False
					continue

			if len(defines) > 0:
				pattern = re.compile(r'\b(' + '|'.join(defines.keys()) + r')\b')
				line = pattern.sub(lambda v: defines[v.group()], line)
				trimmedLine = line.lstrip('\t')

			if line.endswith('//@prevline'):
				sys.stdout.write(trimmedLine[:-len('//@prevline')])
			else:
				if firstLine:
					firstLine = False
				else:
					sys.stdout.write('\n')
				sys.stdout.write(line)
				needNewLine = True

		if needNewLine:
			sys.stdout.write('\n')


parse('.', sys.argv[1])

