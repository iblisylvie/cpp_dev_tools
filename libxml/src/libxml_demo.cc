// Author: iblisylvie@gmail.com (Qian Li)

#include <cassert>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>
#include <string.h>
#include <stdio.h>

xmlDocPtr getdoc(const char *docname) {
  xmlDocPtr doc;
  doc = xmlParseFile(docname);

  if (doc == NULL ) {
    fprintf(stderr,"Document not parsed successfully. \n");
    return NULL;
  }

  return doc;
}

xmlXPathObjectPtr
getnodeset (xmlDocPtr doc, xmlChar *xpath) {

  xmlXPathContextPtr context;
  xmlXPathObjectPtr result;

  context = xmlXPathNewContext(doc);
  if (context == NULL) {
    printf("Error in xmlXPathNewContext\n");
    return NULL;
  }
  result = xmlXPathEvalExpression(xpath, context);
  xmlXPathFreeContext(context);
  if (result == NULL) {
    printf("Error in xmlXPathEvalExpression\n");
    return NULL;
  }
  if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
    xmlXPathFreeObject(result);
                printf("No result\n");
    return NULL;
  }
  return result;
}

int main(int argc, char **argv) {
  std::string xmlContent = "<?xml version=\"1.0\"?>\n"
      "<speak version=\"1.0\" xml:lang=\"en-US\" xmlns=\"http://www.w3.org/2001/10/synthesis\">\n"
      "Welcome to Uni MRCP.\n"
      "</speak>\n";
  xmlContent = "<?xml version=\"1.0\"?>\n"
                "<story>\n"
                "  <storyinfo>\n"
                "    <author>John Fleck</author>\n"
                "    <datewritten>June 2, 2002</datewritten>\n"
                "    <keyword>example keyword</keyword>\n"
                "  </storyinfo>\n"
                "  <body>\n"
                "    <headline>This is the headline</headline>\n"
                "    <para>This is the body text.</para>\n"
                "  </body>\n"
                "</story>";
  xmlDocPtr doc = xmlParseDoc((xmlChar*)xmlContent.c_str());

  xmlChar *xpath = (xmlChar*) "//keyword";

  xmlXPathObjectPtr result = getnodeset (doc, xpath);
  if (result) {
    xmlNodeSetPtr nodeset = result->nodesetval;
    xmlChar *keyword;
    for (int i=0; i < nodeset->nodeNr; i++) {
      keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
      assert(strcmp("example keyword", (char*)keyword) == 0);
      xmlFree(keyword);
    }
    xmlXPathFreeObject (result);
  }
  xmlFreeDoc(doc);
  xmlCleanupParser();
  return 0;
}
