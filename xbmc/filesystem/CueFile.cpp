/*
 *      Copyright (C) 2005-2012 Team XBMC
 *      http://www.xbmc.org
 *

 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "CueFile.h"
#include "SpecialProtocol.h"
#include "URL.h"

#include <sys/stat.h>

using namespace XFILE;

CCueFile::CCueFile(void)
{
}

CCueFile::~CCueFile(void)
{
  Close();
}

bool CCueFile::Open(const CURL& url)
{
  return m_file.Open(url.GetFileName());
}

bool CCueFile::OpenForWrite(const CURL& url, bool bOverWrite /*=false */)
{
  return m_file.OpenForWrite(url.GetFileName(),bOverWrite);
}

bool CCueFile::Delete(const CURL& url)
{
  return m_file.Delete(url.GetFileName());
}

bool CCueFile::Exists(const CURL& url)
{
  return m_file.Exists(url.GetFileName());
}

int CCueFile::Stat(const CURL& url, struct __stat64* buffer)
{
  return m_file.Stat(url.GetFileName(), buffer);
}

bool CCueFile::Rename(const CURL& url, const CURL& urlnew)
{
  return m_file.Rename(url.GetFileName(),urlnew.GetFileName());
}

int CCueFile::Stat(struct __stat64* buffer)
{
  return m_file.Stat(buffer);
}

unsigned int CCueFile::Read(void* lpBuf, int64_t uiBufSize)
{
  return m_file.Read(lpBuf, uiBufSize);
}

int CCueFile::Write(const void* lpBuf, int64_t uiBufSize)
{
  return m_file.Write(lpBuf,uiBufSize);
}

int64_t CCueFile::Seek(int64_t iFilePosition, int iWhence /*=SEEK_SET*/)
{
  return m_file.Seek(iFilePosition, iWhence);
}

void CCueFile::Close()
{
  m_file.Close();
}

int64_t CCueFile::GetPosition()
{
  return m_file.GetPosition();
}

int64_t CCueFile::GetLength()
{
  return m_file.GetLength();
}
